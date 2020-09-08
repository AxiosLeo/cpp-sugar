#!/bin/bash

currpath=$(dirname "$0")
basepath=$(cd "$currpath/../" || exit; pwd)

cd "$basepath/" || exit

find ./src -iname *.hpp -o -iname *.cpp | xargs clang-format -i -style=llvm
find ./include -iname *.hpp -o -iname *.cpp | xargs clang-format -i -style=llvm
find ./tests -iname *.hpp -o -iname *.cpp | xargs clang-format -i -style=llvm
