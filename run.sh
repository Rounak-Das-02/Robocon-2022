#!/bin/sh
if  (ps -aux | grep -v grep | grep "python FinalKeyboardInput.py")
 then
        echo "Running"
else
	echo "Not running"
	python robocon/FinalKeyboardInput.py
        
fi
