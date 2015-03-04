#!/usr/bin/env /bin/sh

if [ $# -lt 1 ]; then
    echo Usage $0 DIR
    exit 1
fi

DIR="$1"

if [ ! -d "$DIR" ]; then
    echo Directory not found
    exit 2
fi

cd "$DIR"
find usr -type f | sort | xargs -n 1 md5sum > DEBIAN/md5sums
