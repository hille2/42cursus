eval $(minikube docker-env)

kubectl delete deployment mysql-deployment
kubectl delete svc mysql-svc
docker build -t mysql_image .

kubectl apply -f mysql.yaml