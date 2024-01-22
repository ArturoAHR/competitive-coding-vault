const { execSync } = require('child_process');
const fs = require('fs');
const path = require('path');

const getLatestTypescriptFile = () => {
  const directories = fs.readdirSync('.').filter(file => fs.statSync(file).isDirectory());

  let latestTypescriptFilePath = null;
  let latestTypescriptFileModificationTime = new Date(0);

  directories.forEach((directory) => {
    const typescriptFiles = fs.readdirSync(directory)
      .filter(file => file.endsWith('.ts'))
      .map((typescriptFile) => {
        return {
          filePath: path.join(directory, typescriptFile),
          modificationTime: fs.statSync(path.join(directory, typescriptFile)).mtime
        }
      })

    typescriptFiles.forEach(({filePath, modificationTime}) => {
      if(modificationTime > latestTypescriptFileModificationTime) {
        latestTypescriptFilePath = filePath,
        latestTypescriptFileModificationTime = modificationTime;
      }
    })
  })

  return latestTypescriptFilePath;
}

const latestTypescriptFile = getLatestTypescriptFile();

if(latestTypescriptFile) {
  try {
    console.log(`Compiling ${latestTypescriptFile}...`);
    execSync(`npx tsc ${latestTypescriptFile}`);

    const compiledJavascriptFile = latestTypescriptFile.replace(/\.ts$/, '.js');
    
    console.log(`Running ${compiledJavascriptFile}...`);
    execSync(`node ${compiledJavascriptFile}`, { stdio: 'inherit' });
  } catch (error) {
    console.error(error);
  }
} else {
  console.log('No TypeScript files found.');
}