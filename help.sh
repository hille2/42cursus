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

#Run Valgrind
valgrind --leak-check=full \
 #        --show-leak-kinds=all \
#         --track-origins=yes \
#         --verbose \
#         --log-file=valgrind-out.txt \
#         ./executable exampleParam1
#The flags are, in short:

#--leak-check=full: "each individual leak will be shown in detail"
#--show-leak-kinds=all: Show all of "definite, indirect, possible, reachable" leak kinds in the "full" report.
#--track-origins=yes: Favor useful output over speed. This tracks the origins of uninitialized values, which could be very useful for memory errors. Consider turning off if Valgrind is unacceptably slow.
#--verbose: Can tell you about unusual behavior of your program. Repeat for more verbosity.
#--log-file: Write to a file. Useful when output exceeds terminal space.
