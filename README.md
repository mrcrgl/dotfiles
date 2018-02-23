# dotfiles


Your *$HOME/.bash_profile* should look like this:

```bash
if [ -f ~/.bashrc ]; then
  source ~/.bashrc
fi
```

In your *$HOME/.bashrc* setup dotfiles like this

```bash
# Example if you're coding go
export GOPATH="$HOME/Code"
export PATH="$PATH:$GOPATH/bin"
export CODEPATH="$GOPATH/src"

source $PATH_TO_REPO/Terminal/standard.inc
```