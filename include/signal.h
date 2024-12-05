#ifndef SIGNAL_H
# define SIGNAL_H

void	sigint_handler(int signo);
void	sigquit_handler(int signo);
void	sigint_handler_child(int signo);
void	sigquit_handler_child(int signo);
void	heredoc_handler(int signo);

#endif
