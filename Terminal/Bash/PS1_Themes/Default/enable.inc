#!/usr/bin/env bash

code_source_dir="${HOME}/Code/src"

alias kernel_version="uname -r"

alias __dotfiles_git_current_branch="git rev-parse --abbrev-ref HEAD"
alias __dotfiles_git_is_initialised="git status -u no -s"
alias __dotfiles_git_root_dir="git rev-parse --show-toplevel"

function relative_repository_path {
    local root_dir=$(__dotfiles_git_root_dir)
    echo "${root_dir/#$code_source_dir\//> }"
}
function relative_project_path {
    local root_dir=$(__dotfiles_git_root_dir)
    if [ ${PWD} != ${root_dir} ]; then
      echo "${PWD/#$root_dir\//:}"
    fi
}
function maybe_bad_exit_code {
    last_exit_code=$?
    if [ ${last_exit_code} != 0 ]; then
      echo -n "< ${last_exit_code} | "
    fi
}

function smart_dir {
    f=`__dotfiles_git_is_initialised & 2>1`; rc=$?; if [ ${rc} -eq 0 ]; then
        echo -e "$(relative_repository_path)@$(__dotfiles_git_current_branch)$(relative_project_path)"
    else
        echo -e "$(pwd)"
    fi
}

# cwd is $HOME
# hostname: ~$

# With process failed with code 128
# hostname: ~ [!128]$

# > github.com/mrcrgl/foobar@master:relative/path $


export PS1="\$(maybe_bad_exit_code)\h: \$(smart_dir) $ "