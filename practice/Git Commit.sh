
read -p "Enter Commit Name : " COMMIT
git add .
git commit -m "$COMMIT"
git push -u origin main
echo "Commit Successful !!!"
