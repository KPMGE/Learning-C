# we can modofy the default target by using the '.DEFAULT_GOAL' phony target

.DEFAULT_GOAL := generate

say_hello: # old default target
	@echo "Hello there!"

generate: # new default target
	@echo "Creating files..."
	@touch file-test.txt

clean:
	@echo "Cleaning up"
	@rm *.txt

