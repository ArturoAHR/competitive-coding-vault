const fs = require('fs');
const path = require('path');

const problemName = process.argv[2];
if (!problemName) {
  console.error('Please specify a problem name');
  process.exit(1);
}

const dirName = problemName;

if (fs.existsSync(dirName)) {
  console.error(`Directory already exists: ${dirName}`);
  process.exit(1);
} else {
  fs.mkdirSync(dirName, { recursive: true });
}

const tsFileTemplate = `/*
 * <Problem title here> 
 * <Problem Link here>
*/

`

const tsFileName = path.join(dirName, `${problemName}.ts`);

if (fs.existsSync(tsFileName)) {
  console.error(`File already exists: ${tsFileName}`);
  process.exit(1);
} else {
  fs.writeFileSync(tsFileName, tsFileTemplate);
  console.log(`Created directory and TypeScript file: ${tsFileName}`);
}

console.log(`Created directory and TypeScript file: ${tsFileName}`);