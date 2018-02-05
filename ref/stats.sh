#!/bin/bash

time ../ia_src/zappy_ai -p $1 -n $2 >zaplog 2>timelog
echo "Fraction of good against bad is $(grep -Ei "take food.*ok" zaplog |wc -l) / $(grep -Ei "take food.*ko" zaplog|wc -l)."
echo "Maximum level is: $(tail zaplog -n 1|grep -Eo "[0-9]")"
