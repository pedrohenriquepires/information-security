#!/usr/bin/env bash

ps ax -o user= | sort | uniq -c
