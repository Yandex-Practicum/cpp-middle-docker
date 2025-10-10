FROM ubuntu@sha256:79efa276fdefa2ee3911db29b0608f8c0561c347ec3f4d4139980d43b168d991

# Update the package database
RUN apt clean
RUN apt update

# Install common tools
RUN apt install -y python3-minimal python3-pip pipx git less vim sudo cmake make g++-15 clang-format clangd-20

#
# Install additional tools and libraries
#

# LLVM/clang tools
RUN apt install -y libllvm-20-ocaml-dev libllvm20 llvm-20 llvm-20-dev llvm-20-doc llvm-20-examples llvm-20-runtime
RUN apt install -y clang-20 clang-tools-20 clang-20-doc libclang-common-20-dev libclang-20-dev libclang1-20 clang-format-20 python3-clang-20 clangd-20 clang-tidy-20

# Network tools and Asio library
RUN apt install -y net-tools libasio-dev netcat-traditional wget

# Graphics tool and SFML library
RUN apt install -y libsfml-dev gnuplot

# Custom allocator library
RUN apt install -y libjemalloc-dev

#
# Cleanup
#
RUN apt autoremove -y \
    && apt autoclean \
    && rm -rf /var/lib/apt/lists/* \
    && rm -rf /var/cache/apt/* \
    && rm -rf /tmp/*

# Update  gcc/g++ version to the latest ones
RUN ln -fs /usr/bin/g++-15 /usr/bin/g++
RUN ln -fs /usr/bin/gcc-15 /usr/bin/gcc

ARG USERNAME=dev
ARG USER_UID=1000
ARG USER_GID=1000

RUN printf "\n\n\nReceived args:\n\tUSERNAME=$USERNAME\n\tUSER_UID=$USER_UID\n\tUSER_GID=$USER_GID\n"
RUN test -n "$USER_UID" && test -n "$USER_GID" || (printf "\n\n\n\tERROR: USER_UID (equal to '$USER_UID') or USER_GID (equal to '$USER_GID') is not set!\n\n\n" && exit 1)

# Delete Ubuntu user to avoid "UID/GID is already exists" problems
RUN set -e; \
    if id -u ubuntu >/dev/null 2>&1; then \
        echo "Delete 'ubuntu' user from the base image"; \
        userdel -r ubuntu 2>/dev/null || true; \
    fi; \
    if getent group ubuntu >/dev/null 2>&1; then \
        echo "Delete 'ubuntu' group from the base image"; \
        groupdel ubuntu 2>/dev/null || true; \
    fi;

# Create a non-root user 'dev' with host UID/GID
RUN set -e; \
    echo "Create group $USERNAME with GID=$USER_GID"; \
    groupadd --gid $USER_GID $USERNAME; \
    \
    echo "Create user $USERNAME with UID=$USER_UID and GID=$USER_GID"; \
    useradd -ms /bin/bash --uid $USER_UID --gid $USER_GID $USERNAME; \
    \
    # Configure NOPASSWD option
    echo "$USERNAME ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/$USERNAME; \
    chmod 0440 /etc/sudoers.d/$USERNAME; \
    \
    echo "User $USERNAME with UID=$USER_UID and GID=$USER_GID was successfully created"

# Switch to non-root user
USER $USERNAME

RUN git config --global core.editor code

# Install conan through pipx
RUN pipx install conan
RUN pipx ensurepath

# Set the default command
CMD ["/bin/bash"]
