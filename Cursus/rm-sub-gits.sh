( find . -type d -name ".git" \
  && find . -name ".gitignore" \
  && find . -name ".gitmodules" ) | xargs rm -rf
