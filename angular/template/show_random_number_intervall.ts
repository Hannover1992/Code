import { Component} from '@angular/core';

@Component({
  selector: 'app-square',
  template: `
  <h1> {{random}} </h1>
  `,
  styles: [
  ]
})
export class SquareComponent {

  random: any;

  constructor(){
    setInterval( () => this.random = Math.random(), 500)
  }
}
