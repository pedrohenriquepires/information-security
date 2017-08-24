# !/bin/bash
# Autor: Paulo Neukamp
# Nome do script: showdate.sh
# Esse script mostra exemplos de saída
# do comando date
# Versão 0.2: primeira versão
# Licença: GPL 2
# $: ./showdate <chave>
# -c mostra a data e hora
# -d mostra somente a data
# Início do Script
# a partir daqui teremos os comandos

case "$1" in
  "") echo "Parâmetro não informado" ;;
  -c) date "+%Y-%m-%d %H:%M:%S" ;;
  -d) date "+%Y-%m-%d" ;;
  *)  echo "Parâmetro <$1> não reconhecido" ;;
esac
