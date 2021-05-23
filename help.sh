# !/sh

#Install Homebrew properly on your 42 session:
curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

#Simply remove these lines from your .zshrc
# Load Homebrew Fix script
source $HOME/.brewconfig.zsh

#install Oh My Zsh
sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"

#install Valgrind on macOS
brew tap LouisBrunner/valgrind
brew install --HEAD LouisBrunner/valgrind/valgrind
