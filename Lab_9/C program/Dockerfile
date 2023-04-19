# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY Lab_3_Program_1.c .
COPY inputfile.txt .
# Compile the C program
RUN gcc -o Lab_3_Program_1 Lab_3_Program_1.c
# Set the command to run when the container starts
CMD ["./Lab_3_Program_1"]