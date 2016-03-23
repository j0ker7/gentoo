# /etc/skel/.bashrc
#
# This file is sourced by all *interactive* bash shells on startup,
# including some apparently interactive shells such as scp and rcp
# that can't tolerate any output.  So make sure this doesn't display
# anything or bad things will happen !


# Test for an interactive shell.  There is no need to set anything
# past this point for scp and rcp, and it's important to refrain from
# outputting anything in those cases.
if [[ $- != *i* ]] ; then
	# Shell is non-interactive.  Be done now!
	return
fi

export PATH=$PATH:/sbin:/usr/sbin

# Put your fun stuff here.
PS1="\n\[$(tput setaf 6)\][ \[$(tput setaf 7)\]\u \[$(tput setaf 6)\]] \[$(tput setaf 6)\][ \[$(tput setaf 5)\]\w \[$(tput setaf 6)\]]\n\[$(tput setaf 3)\]>>> \[$(tput setaf 7)\]"

## help
alias alhelp='cat ~/.bashrc | grep alias'

## dwm
#alias mkdwm='cd ~/dwm-6.0; make && sudo make install && killall dwm; rm -f config.h; cd'
alias mkdwm='cd ~/dwm-6.0; make && sudo make install && rm -f config.h; cd'
alias dwmconfig='vim ~/dwm-6.0/config.def.h'

## portage
alias tail1='sudo tail -f /var/log/emerge-fetch.log'
alias tail2='sudo tail -f /var/log/emerge.log'
alias localuse='sudo vim /etc/portage/package.use/localuse'
alias etcup='sudo etc-update'
alias makeuse='sudo vim /etc/portage/make.conf'
alias sysup='psync && update'
alias psync='sudo emerge --sync && sudo eix-update'
alias update='sudo emerge -avuDN @world'
alias newuse='sudo emerge -avDN @world'
alias depclean='sudo emerge --depclean --verbose --ask'
alias install='sudo emerge -av'
alias uninstall='sudo emerge -cav'
alias search='sudo emerge -s'
alias pv='sudo emerge -pv'
alias world='cat /var/lib/portage/world'

## kernel
alias kernel='cd /usr/src/linux && sudo make menuconfig'
alias kernel2='sudo make && sudo make modules_install'
alias kernel3='sudo make install'

## shortcuts
alias run='sh ~/run'
alias shot="scrot 'scrot-%Y%m%d-%H%M%S.png' -q 100 -cd 3 -e 'mv \$f ~/pictures/scrot/'"
alias clear='clear; sh ~/color/pacman5; pydf'
alias x='clear'
alias off='sudo shutdown -h now'
alias rff='sudo shutdown -r now'
alias ytF='youtube-dl -F'
alias ytf='youtube-dl -f'
alias ssd='sudo smartctl -a /dev/sda'

sh ~/color/pacman5
pydf