@build preset='debug': (setup preset)
	cmake --build --preset {{preset}}

alias gen := setup

@setup preset='debug':
	cmake --preset {{preset}}

@test preset='debug': (build preset)
	ctest --preset {{preset}}

@clean:
	rm -rf build

@sync:
	git submodule update --init --recursive -j 8

@list-builds:
	@cmake --list-presets

[linux]
@ci-deps:
	sudo apt update
	sudo apt install -y cmake build-essential ninja-build

[macos]
@ci-deps:

[windows]
@ci-deps:
# @test: build
# 	ctest --output-on-failure -j --test-dir build

# @build: build/build.ninja
# 	cmake --build build

# @build/build.ninja:
# 	cmake -B build -S . -G Ninja -DK_BUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Debug

# @clean:
# 	rm -rf build

# @dev_linux:
# 	docker build -t chinmaygarde/kdoth .
# 	docker run --rm -it -v ${CURDIR}:/src -w /src chinmaygarde/kdoth /bin/bash
