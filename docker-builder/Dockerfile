FROM ubuntu:latest

WORKDIR /yb-server/build

COPY . /yb-server

ENV CC=/usr/bin/gcc-7
ENV CXX=/usr/bin/g++-7

RUN apt update && apt install -y libmosquittopp-dev cmake g++-7

CMD cmake .. && make && ./ybhome-server
