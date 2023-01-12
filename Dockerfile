FROM gcc:latest
WORKDIR D:\P4
COPY cod.c .
RUN gcc -o cod cod.c -lstdc++
CMD ["./cod"]