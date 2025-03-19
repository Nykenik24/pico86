#!/bin/bash

touch spec/SPEC.txt
cat >>spec/SPEC.txt <<EOL
Spec automatically generated with a script.
This spec's sources were made by Nykenik24 (https://github.com/Nykenik24) for the Pico86 repository (https://github.com/Nykenik24/pico86) for learning purpose.
---

EOL

find "spec" -type f -name "*.txt" | while read -r file; do
	if [[ $file != "spec/SPEC.txt" ]]; then
		cat >>spec/SPEC.txt <<EOS

--- ${file^^} ---
$(cat $file)
EOS
	fi

done

echo "Spec generated, you can find it at spec/SPEC.txt"
