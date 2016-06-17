/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 08:37:11 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 19:07:07 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFF_SIZE 50
# include <libft.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/types.h>
# include <pwd.h>
# include <sys/wait.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>

typedef struct	s_dat
{
	char			**argv;
	char			*prompt;
	char			*init_p;
	size_t			argc;
	char			**env;
	char			*cmd;
	t_lstenv		*t_env;
	struct termios	term;
	struct termios	bterm;
	char			buf[6];
	int				nb_col;
	int				nb_row;
	int				pos_x;
	int				max_x;
	int				vmax_x;
	int				pos_y;
	int				max_y;
	int				replace;
	t_list			*hist;
	int				h_len;
	int				h_pos;
	char			*copy;
}				t_dat;

typedef struct	s_rfd
{
	int				in;
	int				out;
}				t_rfd;

typedef struct	s_mcmd
{
	char			*cmd;
	char			**argv;
	int				argc;
	char			*op;
	t_rfd			*fd;
	int				fd_len;
	int				pos;
	char			**out;
	int				error;
	struct s_mcmd	*next;
	struct s_mcmd	*prev;
}				t_mcmd;

typedef struct	s_cmd
{
	char			*cbin;
	char			**bin;
	int				i;
	DIR				*dir;
	struct dirent	*dp;
}				t_cmd;

typedef struct	s_pipe
{
	int				in[2];
	int				out[2];
}				t_pipe;

typedef struct	s_execmd
{
	pid_t			pid;
	char			**new_env;
	struct passwd	*pw;
	char			ch;
	struct s_pipe	*c;
	struct s_pipe	p;
}				t_execmd;

typedef struct	s_pid
{
	struct s_execmd	*exe;
	struct s_dat	*t_d;
	struct s_mcmd	*cmd;
	int				i;
	int				st;
}				t_pid;

void			ft_select_type(t_dat *t_d);
int				ft_get_list_cmd(t_dat *t_d);
int				ft_is_builtins(t_dat *t_d);
void			ft_print_char_env(char **env, int len);
void			ft_check_env(t_dat *t_d, char ***env);
void			ft_update_shlvl(t_lstenv **t_env);
int				ft_len_argv(char **argv);
void			ft_check_pwd(int state, char *argv);
int				ft_get_spath(char ***argv, char *homedir, int i);
void			ft_get_cmd_argv(t_dat *t_d);
void			ft_update_env(t_dat *t_d, char cwd[1024]);
void			ft_builtins_cd(t_dat *t_d);
void			ft_builtins_history(t_dat *t_d);
int				ft_exit_minishell(t_dat *t_d, int e);
int				ft_init_termios(t_dat *t_d, int i);
int				ft_reset_termios(t_dat *t_d);
void			get_sigint(int sig);
void			ft_init_struct(t_dat *t_d, char *prompt);
void			ft_init_history(t_dat *t_d);
void			ft_add_history(t_dat *t_d);
void			ft_history_top(t_dat *t_d);
void			ft_history_bot(t_dat *t_d);
int				ft_initshell(t_dat *t_d, char *prompt);
int				ft_get_spath(char ***argv, char *homedir, int j);
void			ft_print_char_env(char **env, int len);
int				ft_init_env(char ***env, char **envi);
int				get_action_key(t_dat *t_d);
void			get_action_key_fn3(t_dat *t_d);
int				ft_myputchar(int c);
int				wait_child(void);
void			ft_puterror(char *str, int er);
void			ft_show_cmd(t_dat *t_d, char *cmd);
void			clear_buffer(t_dat *t_d);
void			ft_add_char(t_dat *t_d, char *buf);
void			ft_add_space(char **cmd);
void			ft_replace_cursor(t_dat *t_d);
void			ft_move_cursor(t_dat *t_d);
void			ft_move_end(t_dat *t_d);
void			ft_move_home(t_dat *t_d);
void			ft_move_right(t_dat *t_d);
void			ft_move_left(t_dat *t_d);
void			ft_move_word_right(t_dat *t_d);
void			ft_move_word_left(t_dat *t_d);
void			ft_move_word_down(t_dat *t_d);
void			ft_move_word_up(t_dat *t_d);
void			ft_close_cmd(t_dat *t_d, int i);
void			ft_complet_cmd(t_dat *t_d, int i);
int				ft_close_all_quote(t_dat *t_d, int i);
int				ft_close_read_input(t_dat *t_d, int i);
void			ft_close_pipe(t_dat *t_d, int i);
int				ft_close_cursh(t_dat *t_d, int i);
int				ft_close_parent(t_dat *t_d, int i);
int				ft_close_bracket(t_dat *t_d, int i);
int				ft_read_redirect_cmd(t_mcmd **cmd, char **out);
void			ft_init_new_t_mcmd(t_mcmd **mcmd, char *cmd, t_mcmd *prev,
					int i);
int				ft_isfd_redirect(char *op);
int				ft_isfd_tofd(t_mcmd **cmd, char **argv, int i);
void			ft_add_argv_cmd(t_mcmd **mcmd, char **argv, int i);
void			ft_free_t_mcmd(t_mcmd *cmd, t_execmd *exe);
void			ft_init_pipe(t_execmd *exe, t_mcmd *cmd);
void			ft_free_newenv(char **new_env);
void			ft_update_cmd_path(t_dat *t_d, t_mcmd *cmd);
void			ft_init_new_cmd(t_dat *t_d, t_execmd *exe, t_mcmd *cmd);
void			ft_read_input(t_execmd *exe);
void			ft_next_pid(t_pid *e);
void			ft_pipe_command(t_pid *e);
char			*ft_get_type_redirect(char *op);
int				ft_getfd_in(char *op);
int				ft_getfd_out(char *op, char *str);
void			ft_apply_fd_redirect(t_pid *e);

#endif
