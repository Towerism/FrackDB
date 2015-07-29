#!/bin/sh

if [ "${COVERITY_SCAN_BRANCH}" != 1 ]; then
  bii user "$BII_USER" -p "$BII_PASSWORD"
  bii publish --remote
  coveralls-lcov bii/build/coverage/coverage.info.cleaned
fi
