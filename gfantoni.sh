!#/bin/bash

find . sources lib includes \( -name "*.c" -or -name "*.h" -or -name Makefile \) -exec sed -e 's/josfelip/gfantoni/; s/<josfelip@student.42sp.org.br>/<gfantoni@student.42sp.org.br>/' {} --in-place \;