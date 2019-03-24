import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { DataBindingComponent } from './data-binding/data-binding.component';
import { ServerComponent } from './server/server.component';
import { SelectorAttributeComponent } from './selector-attribute/selector-attribute.component';
import { SelectorClassComponent } from './selector-class/selector-class.component';
import { ComponentBindingComponent } from './component-binding/component-binding.component';

@NgModule({
  declarations: [
    AppComponent,
    DataBindingComponent,
    ServerComponent,
    SelectorAttributeComponent,
    SelectorClassComponent,
    ComponentBindingComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    FormsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
