#!/usr/bin/env bash

TZ='Europe/Brussels'
PREFIX="${1:-$(date '+%Y%m%d')}"

zip ${PREFIX}-archive.zip *.pdf *.xy
cd exports
zip ../${PREFIX}-archive.zip *.ods *.xlsx
cd ../cr/corrections
mv pdf ${PREFIX}-annotations
zip -r ../../${PREFIX}-archive.zip ${PREFIX}-annotations
mv ${PREFIX}-annotations pdf
