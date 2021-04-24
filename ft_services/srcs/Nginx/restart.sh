# !/bin/bash
eval $(minikube docker-env)
kubectl delete svc nginx-svc
kubectl delete deployment nginx-deployment

docker build -t nginx_image .

kubectl apply -f nginx.yaml