'use strict';
const logdata = require('../controllers/logdata');
const about = require('../controllers/about');
const health = require('../controllers/health');

module.exports = (app) => {
    app.route('/').get(logdata.logdata)
    app.route('/health').get(health.health)
    app.route('/about').get(about.about)
};