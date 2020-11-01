
.PHONY: all run run_server run_client clean clean_server clean_target
dir1 = ./mt_server
dir2 = ./mt_client

PORT_SERVER = 46000
export PORT_SERVER

PORT_CLIENT = 46000
export PORT_CLIENT

NUM_CLIENTS = 400
export NUM_CLIENTS

all: subsystem

subsystem:
	cd $(dir1) && $(MAKE)
	cd $(dir2) && $(MAKE)

run: run_server run_client

run_server:
	cd $(dir1) && $(MAKE) run

run_client:
	cd $(dir2) && $(MAKE) run
	
	
clean: clean_server clean_client

clean_server:
	cd $(dir1) && $(MAKE) clean
	
clean_client:
	cd $(dir2) && $(MAKE) clean
