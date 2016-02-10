/**
 * Monitors cycles
 * stored in multi dimensional array
 * [cycle [ strip [ leds [] ]]
 */

import React from 'react';

class Cycle extends React.Component {
    constructor() {
        super();
        this.state = {
            animateCycles: []
        };
    }
    animateArray() {
        let array  = [];
        let strips = 8;
        let leds   = 30;

        for (let i = 0; i < strips; i++) {
            array[i] = [];
            for (let j = 0; j < leds; j++) {
                array[i][j] = 0;
            }
        }
        return array;
    }
    pushCycle() {
        console.log('adding cycle');
    }
    popCycle() {
        console.log('removing cycle');
    }
    render() {
        return (
            <div id="cycle">
                <div className="btn-group">
                    <button type="button" className="btn btn-default" onClick={ this.popCycle }>
                        <i className="glyphicon glyphicon-chevron-left"></i>
                    </button>
                    <button type="button" className="btn btn-default" onClick={ this.pushCycle }>
                        <i className="glyphicon glyphicon-chevron-right"></i>
                    </button>
                </div>
            </div>
        )
    }
}

export default Cycle
