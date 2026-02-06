const path = require('path');

module.exports = {
  entry: path.resolve(__dirname, './main.js'),
  module: {
    rules: [
      {
        test: /\.(js)$/,
        exclude: /node_modules/
      }
    ]
  },
  resolve: {
    extensions: ['*', '.js']
  },
  output: {
    path: path.resolve(__dirname, '.'),
    filename: '../data/bundle.js',
  },
  devServer: {
    static: path.resolve(__dirname, '.'),
  },
};
