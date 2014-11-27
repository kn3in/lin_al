build:
	c++ ols.cpp -o ls -I eigen322

set_eigen:
	mkdir eigen322
	curl -L http://bitbucket.org/eigen/eigen/get/3.2.2.tar.gz | tar -xz - -C eigen322 --strip-components=1
