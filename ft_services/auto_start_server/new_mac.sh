	# !/bin/bash
    rm -rf ~/.minikube
    #check if BREW is installed.
    #if NOT:
    #curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
    brew install minikube
    #else:
    #brew reinstall minikube
    
    minikube start --vm-driver=virtualbox
    mv ~/.minikube ~/goinfre
    ln -s ~/goinfre/.minikube ~/.minikube
    minikube delete
    minikube start --vm-driver=virtualbox
    minikube addons enable metallb
    
    kubectl apply -f ../srcs/configmap.yaml
    eval $(minikube docker-env)
