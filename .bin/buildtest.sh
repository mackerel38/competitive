#!/bin/bash


# ビルドの実行
g++ -std=c++20 -D poe -g -O0 -march=native "$1/main.cpp" -I /workspaces/competitive/library -o /workspaces/competitive/a.out

# ビルドが成功した場合にoj testを実行
if [ $? -eq 0 ]; then
    oj test -c /workspaces/competitive/a.out -d $1/test -S -N
else
    echo "Build failed. Skipping oj test."
fi
