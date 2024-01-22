const fs = require('fs');
const path = require('path');

const problemName = process.argv[2];
if (!problemName) {
  console.error('Please specify a problem name');
  process.exit(1);
}

const dirName = problemName;
fs.mkdirSync(dirName, { recursive: true });

const tsFileTemplate = `/*
 * <Problem title here> 
 * <Problem Link here>
*/

`

const tsFileName = path.join(dirName, `${problemName}.ts`);
fs.writeFileSync(tsFileName, tsFileTemplate);

console.log(`Created directory and TypeScript file: ${tsFileName}`);