import React from 'react';

class Light extends React.Component {

    constructor( props ) {

        super( props );

        this.iColour = '#777';

        this.state = {
            active: ( this.props.colour !== null ),
            activeClass: ( this.props.colour !== null ) ? 'active' : '',
            activeStyle: {
                color: ( this.props.colour !== null) ? this.props.colour : this.iColour
            },
            colour: this.props.colour
        };
    }

    toggleActive() {
        this.setState(( state )=> {
            return {
                active: !state.active,
                activeClass: ( state.active ) ? '' : 'active',
                activeStyle: {
                    color: ( state.active ) ? this.iColour : state.colour
                },
                colour: this.props.colour
            }
        });
    }

    componentWillReceiveProps( nextProps ) {
        this.setState(( state )=> {
            return {
                active: ( nextProps.colour !== null ),
                activeClass: ( nextProps.colour !== null ) ? 'active' : '',
                activeStyle: {
                    color: ( nextProps.colour !== null) ? nextProps.colour : this.iColour
                },
                colour: nextProps.colour
            };
        });
    }

    render() {
        return (
            <a className={ this.state.activeClass } style={ this.state.activeStyle } onClick={ this.toggleActive.bind(this) }></a>
        )
    }
}

export default Light
