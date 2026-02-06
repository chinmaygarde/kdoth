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
