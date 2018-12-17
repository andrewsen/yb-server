FROM ubuntu:latest

WORKDIR /yb-server

COPY . /yb-server

RUN apt update && apt install -y libmosquittopp-dev

EXPOSE 1883

CMD ["./ybhome-server"]
