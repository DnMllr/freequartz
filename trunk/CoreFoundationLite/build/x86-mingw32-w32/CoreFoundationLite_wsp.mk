.PHONY: clean All

All:
	@echo ----------Building project:[ CoreFoundationLite - Debug ]----------
	@"mingw32-make.exe"  -j 2 -f "CoreFoundationLite.mk"
clean:
	@echo ----------Cleaning project:[ CoreFoundationLite - Debug ]----------
	@"mingw32-make.exe"  -j 2 -f "CoreFoundationLite.mk" clean
