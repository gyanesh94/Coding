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
import { BasicHighlightDirective } from './directives/basic-highlight.directive';
import { BetterHighlightDirective } from './directives/better-highlight.directive';
import { UnlessDirective } from './directives/unless.directive';
import { CustomStructuralDirectiveExampleComponent } from './custom-structural-directive-example/custom-structural-directive-example.component';
import { NgSwitchExampleComponent } from './ng-switch-example/ng-switch-example.component';
import { AppLoggingServiceExampleComponent } from './app-logging-service-example/app-logging-service-example.component';

@NgModule({
  declarations: [
    AppComponent,
    DataBindingComponent,
    ServerComponent,
    SelectorAttributeComponent,
    SelectorClassComponent,
    ComponentBindingComponent,
    BasicHighlightDirective,
    BetterHighlightDirective,
    UnlessDirective,
    CustomStructuralDirectiveExampleComponent,
    NgSwitchExampleComponent,
    AppLoggingServiceExampleComponent
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
