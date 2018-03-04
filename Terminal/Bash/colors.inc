#!/usr/bin/env bash

#GREEN=$(tput setaf 034)
#TEXT_COLOR_BLACK=$(tput setaf 0)
#TEXT_COLOR_RED=$(tput setaf 1)
#TEXT_COLOR_GREEN=$(tput setaf 2)
#TEXT_COLOR_YELLOW=$(tput setaf 3)
#TEXT_COLOR_BLUE=$(tput setaf 4)
#TEXT_COLOR_MAGENTA=$(tput setaf 5)
#TEXT_COLOR_CYAN=$(tput setaf 6)
#TEXT_COLOR_WHITE=$(tput setaf 7)
#TEXT_BOLD=$(tput bold)
#TEXT_RESET=$(tput sgr0)

TEXT_HALF_BRIGHT=$(tput dim)

TEXT_RESET="\[\033[0m\]"

# regular colors
TEXT_COLOR_BLACK="\[\033[0;30m\]"    # black
TEXT_COLOR_RED="\[\033[0;31m\]"      # red
TEXT_COLOR_GREEN="\[\033[0;32m\]"    # green
TEXT_COLOR_YELLOW="\[\033[0;33m\]"   # yellow
TEXT_COLOR_BLUE="\[\033[0;34m\]"     # blue
TEXT_COLOR_MAGENTA="\[\033[0;35m\]"  # magenta
TEXT_COLOR_CYAN="\[\033[0;36m\]"     # cyan
TEXT_COLOR_WHITE="\[\033[0;37m\]"    # white
    
# emphasized (bolded) colors
EMK="\[\033[1;30m\]"
EMR="\[\033[1;31m\]"
EMG="\[\033[1;32m\]"
EMY="\[\033[1;33m\]"
EMB="\[\033[1;34m\]"
EMM="\[\033[1;35m\]"
EMC="\[\033[1;36m\]"
EMW="\[\033[1;37m\]"
    
# background colors
BGK="\[\033[40m\]"
BGR="\[\033[41m\]"
BGG="\[\033[42m\]"
BGY="\[\033[43m\]"
BGB="\[\033[44m\]"
BGM="\[\033[45m\]"
BGC="\[\033[46m\]"
BGW="\[\033[47m\]"