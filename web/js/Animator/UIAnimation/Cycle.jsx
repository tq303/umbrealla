/**
 * Monitors cycles
 * stored in multi dimensional array
 * [cycle [ strip [ leds [] ]]
 */

import React from 'react';

class Cycle extends React.Component {
    constructor( props ) {
        super( props );
        this.state = {
            animateCycles: [this.animateArray()],
            cyclePosition: 1,
            undoCycle: this.defaultUndoCycle(),
            ledPosition: 1
        };
    }
    animateArray() {
        let array  = [];

        for (let i = 0; i < window.STRIP_COUNT; i++) {
            array[i] = [];
            for (let j = 0; j < window.LED_COUNT; j++) {
                array[i][j] = 0;
            }
        }

        return array;
    }
    defaultUndoCycle() {
        return {
            position: null,
            cycle: null
        }
    }
    pushCycle() {
        if (this.state.animateCycles.length === this.state.cyclePosition) {
            this.setState((state) => {
                animateCycles: state.animateCycles.push( this.getLastCycle() )
            });
        }
        this.setState((state) => {
            cyclePosition: state.cyclePosition++
        });
    }
    popCycle() {
        if (this.state.cyclePosition > 1) {
            this.setState((state) => {
                cyclePosition: state.cyclePosition--
            });
        }
    }
    insertCycle() {
        this.setState((state) => {
            animateCycles: state.animateCycles.splice( (state.cyclePosition - 1), 0, this.getCurrentCycle() )
        });
    }
    deleteCycle() {
        if (this.state.animateCycles.length > 1) {

            this.state.animateCycles.splice( this.state.animateCycles.indexOf( this.getCurrentCycleRef() ), 1 );
            let newCycles = this.state.animateCycles;

            this.setState((state) => {
                return {
                    undoCycle: {
                        position: (state.cyclePosition - 1),
                        cycle: this.getCurrentCycle()
                    },
                    animateCycles: newCycles
                }
            });

            if (this.state.cyclePosition > this.state.animateCycles.length) {
                this.setState((state) => {
                    cyclePosition: state.cyclePosition--
                });
            }

        }
    }
    undoDeleteCycle() {
        if (this.state.undoCycle.position !== null && this.state.undoCycle.cycle !== null) {

            this.state.animateCycles.splice( this.state.undoCycle.position, 0, this.state.undoCycle.cycle );
            let newCycles = this.state.animateCycles;

            this.setState((state) => {
                return {
                    animateCycles: newCycles,
                    undoCycle: this.defaultUndoCycle()
                }
            });

        }
    }
    getLastCycle() {
        return this.state.animateCycles.slice()[0];
    }
    getCurrentCycle() {
        return this.state.animateCycles.slice(( this.state.cyclePosition - 1 ), 1)[0];
    }
    getCurrentCycleRef() {
        return this.state.animateCycles[( this.state.cyclePosition - 1 )];
    }
    updateLedPosition( e ) {
        if (e.target.value >= 1 && e.target.value <= window.LED_COUNT) {
            this.setState({
                ledPosition: e.target.value
            });
        }
    }
    render() {
        return (
            <div id="cycle">

                <div>

                    <button onClick={ this.popCycle.bind(this) }>
                        <i className="fa fa-step-backward"></i>
                    </button>
                    <button onClick={ this.pushCycle.bind(this) }>
                        <i className="fa fa-step-forward"></i>
                    </button>

                    <span>{ this.state.cyclePosition }</span>/<span>{ this.state.animateCycles.length }</span>

                </div>


                <div>
                    <input value={ this.state.ledPosition } onChange={ this.updateLedPosition.bind(this) } type="number" />
                </div>

                <div>

                    <button onClick={ this.insertCycle.bind(this) }>
                        <i className="fa fa-plus"></i>
                    </button>
                    <button disabled={ this.state.animateCycles.length === 1 } onClick={ this.deleteCycle.bind(this) }>
                        <i className="fa fa-minus"></i>
                    </button>
                    <button disabled={ !this.state.undoCycle.position } onClick={ this.undoDeleteCycle.bind(this) }>
                        <i className="fa fa-undo"></i>
                    </button>

                </div>

            </div>
        )
    }
}

export default Cycle;
