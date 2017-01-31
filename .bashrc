if [[ `whoami` != 'root' ]]; then
	PS1='\[\e[0;32m\]\u\[\e[0m\]@\h \W\[\e[0;32m\] \$\[\e[0m\] '
else
	PS1='\[\e[0;31m\]\u\[\e[0m\]@\h \W\[\e[0;31m\] \$\[\e[0m\] '
fi
export VISUAL=vim
alias ls='ls --color=auto'
alias grep='grep --color=auto'
alias less='/usr/share/vim/vim74/macros/less.sh'
alias vim='TERM=screen-256color vim'
man() {
	env LESS_TERMCAP_mb=$'\E[01;31m' \
		LESS_TERMCAP_md=$'\E[01;38;5;74m' \
		LESS_TERMCAP_me=$'\E[0m' \
		LESS_TERMCAP_se=$'\E[0m' \
		LESS_TERMCAP_so=$'\E[38;5;246m' \
		LESS_TERMCAP_ue=$'\E[0m' \
		LESS_TERMCAP_us=$'\E[04;38;5;146m' \
		man "$@"
}
