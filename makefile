all:
	gcc -g -o log_string log_string.c
	gcc -o translator translator.c

test:
	@objdump -h log_string | grep "\.log\.text" | awk '{print "dd if='log_string' of='log_text_section' bs=1 count=$$[0x" $$3 "] skip=$$[0x" $$6 "]"}' | bash
	@echo ""
	@echo "log output"
	@echo "=========="
	@./log_string
	@echo ""
	@echo "translator output"
	@echo "=========="
	@objdump -h log_string | grep "\.log\.text" | awk '{print "./log_string | ./translator 0x" $$5}' | bash | tee translator.gdb
	@echo "call gdb to translate"
	@echo "=========="
	@gdb log_string -x translator.gdb
