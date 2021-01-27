#!/bin/bash
blih -u jack.goodall@epitech.eu repository create $1
blih -u jack.goodall@epitech.eu repository setacl $1 ramassage-tek r
blih -u jack.goodall@epitech.eu repository getacl $1

