#!/bin/bash
cut -d";" -f 3 | grep -wi "$1" | wc -w

