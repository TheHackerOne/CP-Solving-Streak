
while read -p "Enter Commit Name : " COMMIT
  do    
    git add .
    git commit -m "$COMMIT"
    git push -u origin main
    echo "Commit Successful !!!"
    read -p "Press any key!!"
    clear
done
