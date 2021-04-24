# !/bin/bash
eval $(minikube docker-env)
kubectl delete deployment phpma-deployment
kubectl delete svc phpma-svc

docker build -t phpma_image .
kubectl apply -f phpma.yaml