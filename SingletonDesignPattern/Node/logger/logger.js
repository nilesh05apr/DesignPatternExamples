class Loggger {
    constructor() {
        if(Loggger.instance == null){
            this.logs = []
            Loggger.instance = this
        }
        return Loggger.instance
    }

    log(message) {
        this.logs.push(message)
        console.log(`${message}`)
    }

    logCount() {
        console.log(`${this.logs.length} logs`)
    }
}

const logger = new Loggger();
Object.freeze(logger);
module.exports = new Loggger();