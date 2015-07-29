#!/bin/sh
if [ "${COVERITY_SCAN_BRANCH}" != 1 ]; then
  make coverage
fi
