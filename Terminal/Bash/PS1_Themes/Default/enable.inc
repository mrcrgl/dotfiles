#!/usr/bin/env bash

source ${BASH_SOURCE%/*}/../../colors.inc

code_source_dir=${CODEPATH:-"${HOME}/Code/src"}

alias __dotfiles_git_current_branch="git rev-parse --abbrev-ref HEAD"
alias __dotfiles_git_is_initialised="git status -u no -s"
alias __dotfiles_git_root_dir="git rev-parse --show-toplevel"

function __dotfiles_refresh_git_root_dir {
    if [ ${__dotfiles_var_git_is_initialised} == true ]; then
        __dotfiles_var_git_root_dir=$(__dotfiles_git_root_dir)
    else 
        __dotfiles_var_git_root_dir=""
    fi
}

function __dotfiles_refresh_git_is_initialised {
    __dotfiles_git_is_initialised > /dev/null 2>&1
    rc=$?
    if [ ${rc} -eq 0 ]; then
        __dotfiles_var_git_is_initialised=true
    else 
        __dotfiles_var_git_is_initialised=false
    fi
}

function __dotfiles_relative_repository_path {
    echo "${__dotfiles_var_git_root_dir/#$code_source_dir\//}"
}

function __dotfiles_relative_project_path {
    if [ ${PWD} != ${__dotfiles_var_git_root_dir} ]; then
      echo ${PWD/#$__dotfiles_var_git_root_dir\//}
    fi
}
function __dotfiles_refresh_bad_exit_code {
    __dotfiles_var_last_exit_code=$?
    if [ ${__dotfiles_var_last_exit_code} != 0 ]; then
        __dotfiles_var_bad_exit_code="!${__dotfiles_var_last_exit_code}"
        __dotfiles_var_bad_exit_code_suffix=" | "
    else
        __dotfiles_var_bad_exit_code=""
        __dotfiles_var_bad_exit_code_suffix=""
    fi
}

function __dotfiles_refresh_code_smart_dir {
    if [ ${__dotfiles_var_git_is_initialised} == true ]; then
        __dotfiles_var_non_code_path=""
        __dotfiles_var_code_prefix="> "
        __dotfiles_var_code_repo=$(__dotfiles_relative_repository_path)
        __dotfiles_var_code_branch_sep="@"
        __dotfiles_var_code_branch=$(__dotfiles_git_current_branch)
        __dotfiles_var_code_path=$(__dotfiles_relative_project_path)
        if [ "${__dotfiles_var_code_path}" != "" ]; then
            __dotfiles_var_code_path_sep=":"
        else
            __dotfiles_var_code_path_sep=""
        fi
    else
        __dotfiles_var_non_code_path="${PWD/#$HOME/~}"

        __dotfiles_var_code_prefix=""
        __dotfiles_var_code_repo=""
        __dotfiles_var_code_branch_sep=""
        __dotfiles_var_code_branch=""
        __dotfiles_var_code_path_sep=""
        __dotfiles_var_code_path=""
    fi
}

__dotfiles_var_last_exit_code=0
__dotfiles_var_git_root_dir=""

__dotfiles_var_bad_exit_code=""
__dotfiles_var_bad_exit_code_suffix=""

__dotfiles_var_git_is_initialised=false
__dotfiles_var_non_code_path=""
__dotfiles_var_code_prefix=""
__dotfiles_var_code_repo=""
__dotfiles_var_code_branch_sep=""
__dotfiles_var_code_branch=""
__dotfiles_var_code_path_sep=""
__dotfiles_var_code_path=""

# cwd is $HOME
# hostname: ~$

# With process failed with code 128
# hostname: ~ [!128]$

# > github.com/mrcrgl/foobar@master:relative/path $
# (exit code)(normal path)(git path prefix)(git repo)(git branch divider)(git branch)(git path divider)(git path)

bash_prompt_command() {
    __dotfiles_var_last_exit_code=$?
    __dotfiles_refresh_git_is_initialised
    __dotfiles_refresh_git_root_dir
    __dotfiles_refresh_bad_exit_code
    __dotfiles_refresh_code_smart_dir
}

export PROMPT_COMMAND=bash_prompt_command
export PS1="${TEXT_COLOR_RED}\${__dotfiles_var_bad_exit_code}${TEXT_RESET}\${__dotfiles_var_bad_exit_code_suffix}${TEXT_COLOR_CYAN}\${__dotfiles_var_non_code_path}${TEXT_RESET}\${__dotfiles_var_code_prefix}${TEXT_COLOR_MAGENTA}\${__dotfiles_var_code_repo}${TEXT_RESET}${TEXT_HALF_BRIGHT}\${__dotfiles_var_code_branch_sep}${TEXT_RESET}\${__dotfiles_var_code_branch}\${__dotfiles_var_code_path_sep}${TEXT_COLOR_CYAN}\${__dotfiles_var_code_path}${TEXT_RESET} $ "
